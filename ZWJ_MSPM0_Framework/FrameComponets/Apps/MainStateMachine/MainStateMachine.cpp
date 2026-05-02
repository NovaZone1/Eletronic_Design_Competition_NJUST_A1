#include "MainStateMachine.hpp"
#include "Follow.hpp"
#include "Navigation.hpp"
#include "Overtake.hpp"
#include "SpeedMixer.hpp"
#include "System.hpp"
#include "Track.hpp"

StateGraph MainStateMachine::main_graph("MainGraph");
StateBlock *MainStateMachine::st_idle = nullptr;
StateBlock *MainStateMachine::st_line_follow = nullptr;
StateBlock *MainStateMachine::st_follow = nullptr;
StateBlock *MainStateMachine::st_overtake = nullptr;
StateBlock *MainStateMachine::st_turn_around = nullptr;
StateBlock *MainStateMachine::st_navigation = nullptr;
StateBlock *MainStateMachine::st_finish = nullptr;

bool MainStateMachine::cond_start = false;
bool MainStateMachine::cond_has_car = false;
bool MainStateMachine::cond_no_car = false;
bool MainStateMachine::cond_dashed_line = false;
bool MainStateMachine::cond_overtake_done = false;
bool MainStateMachine::cond_finish_line = false;
bool MainStateMachine::cond_turn_done = false;
bool MainStateMachine::cond_nav_start = false;
bool MainStateMachine::cond_nav_done = false;

// ========== 公共接口实现 ==========
void MainStateMachine::Init() {
    RegisterAllApps();      // 1. 先注册所有 App
    InitStateBlocks();      // 2. 再初始化状态块
    InitStateTransitions(); // 3. 最后建立状态转换链接
}

void MainStateMachine::Start() {
    StateCore &core = StateCore::GetInstance();
    core.RegistGraph(main_graph); // 注册主状态图
    core.Enable(0);               // 从第 0 个状态图开始执行
}

const char *MainStateMachine::GetCurrentStateName() {
    StateCore &core = StateCore::GetInstance();
    return core.GetCurState().name;
}

// ========== 内部初始化函数实现 ==========
void MainStateMachine::RegisterAllApps() {
    // 按顺序注册所有 App 到 System
    System.RegistApp(track);
    System.RegistApp(follow);
    System.RegistApp(overtake);
    System.RegistApp(navigation);
}

void MainStateMachine::InitStateBlocks() {
    // 1. 添加所有状态块到状态图
    st_idle = &main_graph.AddState("Idle");
    st_line_follow = &main_graph.AddState("LineFollow");
    st_follow = &main_graph.AddState("Follow");
    st_overtake = &main_graph.AddState("Overtake");
    st_turn_around = &main_graph.AddState("TurnAround");
    st_navigation = &main_graph.AddState("Navigation");
    st_finish = &main_graph.AddState("Finish");

    // 2. 绑定每个状态的执行函数
    st_idle->StateAction = ActionIdle;
    st_line_follow->StateAction = ActionLineFollow;
    st_follow->StateAction = ActionFollow;
    st_overtake->StateAction = ActionOvertake;
    st_turn_around->StateAction = ActionTurnAround;
    st_navigation->StateAction = ActionNavigation;
    st_finish->StateAction = ActionFinish;
}

void MainStateMachine::InitStateTransitions() {
    // ========== 状态转换链接定义（核心！所有跳转都在这里） ==========
    // 注意：用 cond_no_car 代替 &!cond_has_car，解决编译错误

    // 空闲 → 巡线
    st_idle->LinkTo(&cond_start, *st_line_follow);

    // 巡线 ↔ 跟车（双向转换）
    st_line_follow->LinkTo(&cond_has_car, *st_follow);
    st_follow->LinkTo(&cond_no_car, *st_line_follow); // 用反向条件

    // 巡线/跟车 → 超车
    st_line_follow->LinkTo(&cond_dashed_line, *st_overtake);
    st_follow->LinkTo(&cond_dashed_line, *st_overtake);

    // 超车 → 跟车
    st_overtake->LinkTo(&cond_overtake_done, *st_follow);

    // 巡线/跟车 → 掉头
    st_line_follow->LinkTo(&cond_finish_line, *st_turn_around);
    st_follow->LinkTo(&cond_finish_line, *st_turn_around);

    // 掉头 → 巡线
    st_turn_around->LinkTo(&cond_turn_done, *st_line_follow);

    // 任意状态 → 导航
    st_line_follow->LinkTo(&cond_nav_start, *st_navigation);
    st_follow->LinkTo(&cond_nav_start, *st_navigation);

    // 导航 → 结束
    st_navigation->LinkTo(&cond_nav_done, *st_finish);
}

// ========== 状态动作函数实现（核心联动逻辑） ==========
/**
 * @brief 空闲状态动作
 * @note 所有 App 禁用，等待开始信号
 */
void MainStateMachine::ActionIdle(StateCore *core) {
    // 1. 禁用所有 App
    track.SetEnable(false);
    follow.SetEnable(false);
    overtake.SetEnable(false);
    navigation.SetEnable(false);

    // 2. 清除 SpeedMixer 所有速度设置
    speed_mixer.ClearAll();

    // 3. 检测开始按键（根据实际硬件修改）
    // 示例：if (Key_IsPressed(KEY_START)) cond_start = true;
}

/**
 * @brief 纯巡线状态动作
 * @note 只启用 Track，禁用其他，更新巡线相关条件
 */
void MainStateMachine::ActionLineFollow(StateCore *core) {
    // 1. 启用/禁用对应 App
    track.SetEnable(true);
    follow.SetEnable(false);
    overtake.SetEnable(false);
    navigation.SetEnable(false);

    // 2. 清除不需要的 SpeedMixer 来源
    speed_mixer.ClearSource(SpeedMixer::Source::FOLLOW);
    speed_mixer.ClearSource(SpeedMixer::Source::OVERTAKE);
    // speed_mixer.ClearSource(SpeedMixer::Source::NAVIGATION);

    // 3. 更新状态转换条件（从 App 读取标志）
    cond_has_car = (follow.real_dist > 0 && follow.real_dist < 50.0f); // 前方50cm内有车
    cond_no_car = !cond_has_car;                                       // 关键：更新反向条件
    cond_dashed_line = track.is_dashed_line;
    // cond_finish_line = track.IsFinishLine(); // 需自行实现终点检测
}

/**
 * @brief 巡线+跟车状态动作
 * @note 同时启用 Track 和 Follow，更新跟车相关条件
 */
void MainStateMachine::ActionFollow(StateCore *core) {
    // 1. 启用/禁用对应 App
    track.SetEnable(true);
    follow.SetEnable(true);
    overtake.SetEnable(false);
    navigation.SetEnable(false);

    // 2. 清除不需要的 SpeedMixer 来源
    speed_mixer.ClearSource(SpeedMixer::Source::OVERTAKE);
    speed_mixer.ClearSource(SpeedMixer::Source::NAVIGATION);

    // 3. 更新状态转换条件
    cond_has_car = (follow.real_dist > 0 && follow.real_dist < 50.0f);
    cond_no_car = !cond_has_car; // 关键：更新反向条件
    cond_dashed_line = track.is_dashed_line;
    // cond_finish_line = track.IsFinishLine();
}

/**
 * @brief 超车状态动作
 * @note 只启用 Overtake，启动超车流程
 */
void MainStateMachine::ActionOvertake(StateCore *core) {
    // 1. 启用/禁用对应 App
    track.SetEnable(false);
    follow.SetEnable(false);
    overtake.SetEnable(true);
    navigation.SetEnable(false);

    // 2. 清除不需要的 SpeedMixer 来源
    speed_mixer.ClearSource(SpeedMixer::Source::TRACK);
    speed_mixer.ClearSource(SpeedMixer::Source::FOLLOW);
    speed_mixer.ClearSource(SpeedMixer::Source::NAVIGATION);

    // 3. 启动超车（仅在进入状态时执行一次）
    static bool first_enter = true;
    if (first_enter) {
        overtake.StartOvertake();
        first_enter = false;
    }

    // 4. 更新完成标志
    cond_overtake_done = overtake.is_complete;

    // 5. 退出状态时重置标志
    if (cond_overtake_done) {
        first_enter = true;
        cond_dashed_line = false; // 清除虚线标志，避免重复触发
    }
}

/**
 * @brief 掉头状态动作
 * @note 所有 App 禁用，直接执行掉头逻辑
 */
void MainStateMachine::ActionTurnAround(StateCore *core) {
    // 1. 禁用所有 App
    track.SetEnable(false);
    follow.SetEnable(false);
    overtake.SetEnable(false);
    navigation.SetEnable(false);

    // 2. 清除 SpeedMixer 所有速度设置
    speed_mixer.ClearAll();

    // 3. 执行掉头逻辑（示例：原地转 180 度）
    static uint32_t turn_timer = 0;
    if (turn_timer < 200) { // 200Hz 下 1 秒
        // 直接设置 SpeedMixer 掉头速度
        speed_mixer.SetOvertakeSpeed(-100, 100);
        turn_timer++;
    } else {
        // 停止
        speed_mixer.SetOvertakeSpeed(0, 0);
        cond_turn_done = true;
        turn_timer = 0;
    }
}

/**
 * @brief 导航状态动作
 * @note 只启用 Navigation
 */
void MainStateMachine::ActionNavigation(StateCore *core) {
    // 1. 启用/禁用对应 App
    track.SetEnable(false);
    follow.SetEnable(false);
    overtake.SetEnable(false);
    navigation.SetEnable(true);

    // 2. 清除不需要的 SpeedMixer 来源
    speed_mixer.ClearSource(SpeedMixer::Source::TRACK);
    speed_mixer.ClearSource(SpeedMixer::Source::FOLLOW);
    speed_mixer.ClearSource(SpeedMixer::Source::OVERTAKE);

    // 3. 更新完成标志
    cond_nav_done = navigation.is_complete;
}

/**
 * @brief 结束状态动作
 * @note 所有 App 禁用，电机停止
 */
void MainStateMachine::ActionFinish(StateCore *core) {
    // 1. 禁用所有 App
    track.SetEnable(false);
    follow.SetEnable(false);
    overtake.SetEnable(false);
    navigation.SetEnable(false);

    // 2. 清除 SpeedMixer 所有速度设置
    speed_mixer.ClearAll();
}