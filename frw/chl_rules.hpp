struct chl_rules {
    bool timed = false;
    int timed_deadline = 0;
    int double_dips = 0;
    bool allows_releasing = false;
    bool in_order = false;
    bool finished_before_post_creation = false;
    bool started_before_post_creation = false;
    int minimum_runtime_per_entry = 30;
    int minimum_total_runtime = 0;
    int maximum_total_runtime = 0;
};