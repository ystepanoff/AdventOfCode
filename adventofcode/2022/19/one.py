import re


def bfs(
    ore_robot_ore,
    clay_robot_ore,
    obs_robot_ore,
    obs_robot_clay,
    geode_robot_ore,
    geode_robot_obs,
    time
):
    best = 0
    q = [(time, 1, 0, 0, 0, 0, 0, 0, 0)]
    vis = set()
    for t, r_ore, r_clay, r_obs, r_geode, ore, clay, obs, geode in q:
        best = max(best, geode)
        if geode < best:
            continue
        if t == 0:
            continue
        states = []
        if ore >= geode_robot_ore and obs >= geode_robot_obs:
            states.append(
                (
                    t - 1,
                    r_ore,
                    r_clay,
                    r_obs,
                    r_geode + 1,
                    ore + r_ore - geode_robot_ore,
                    clay + r_clay,
                    obs + r_obs - geode_robot_obs,
                    geode + r_geode,
                )
            )
        if ore >= obs_robot_ore and clay >= obs_robot_clay:
            states.append(
                (
                    t - 1,
                    r_ore,
                    r_clay,
                    r_obs + 1,
                    r_geode,
                    ore + r_ore - obs_robot_ore,
                    clay + r_clay - obs_robot_clay,
                    obs + r_obs,
                    geode + r_geode,
                )
            )
        if ore >= clay_robot_ore:
            states.append(
                (
                    t - 1,
                    r_ore,
                    r_clay + 1,
                    r_obs,
                    r_geode,
                    ore + r_ore - clay_robot_ore,
                    clay + r_clay,
                    obs + r_obs,
                    geode + r_geode,
                )
            )
        if ore >= ore_robot_ore:
            states.append(
                (
                    t - 1,
                    r_ore + 1,
                    r_clay,
                    r_obs,
                    r_geode,
                    ore + r_ore - ore_robot_ore,
                    clay + r_clay,
                    obs + r_obs,
                    geode + r_geode,
                )
            )
        states.append(
            (
                t - 1,
                r_ore,
                r_clay,
                r_obs,
                r_geode,
                ore + r_ore,
                clay + r_clay,
                obs + r_obs,
                geode + r_geode,
            )
        )
        for st in states:
            if st not in vis:
                q.append(st)
                vis.add(st)
    return best


total = 0
for line in open('input'):
    if not line.rstrip():
        continue
    (
        bp_index,
        ore_robot_ore,
        clay_robot_ore,
        obs_robot_ore,
        obs_robot_clay,
        geode_robot_ore,
        geode_robot_obs,
    ) = map(int, re.findall(r'\d+', line))
    max_geodes = bfs(
        ore_robot_ore,
        clay_robot_ore,
        obs_robot_ore,
        obs_robot_clay,
        geode_robot_ore,
        geode_robot_obs,
        24,
    )
    total += bp_index * max_geodes
    print(bp_index, max_geodes, total)
