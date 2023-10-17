class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCount(26, 0);

        for (char task : tasks) {
            taskCount[task - 'A']++;
        }

        sort(taskCount.begin(), taskCount.end(),greater<int>()); //descending order
        int maxCount = taskCount[0]; //max freq task
        int idleTime = (maxCount - 1) * n; //calculating its idle time
        int availableTasks = maxCount - 1; //other tasks
        // Distribute other tasks that don't require idle time
        for (int i = 1; i < 26 && taskCount[i] > 0; i++) {
            idleTime -= min(taskCount[i], availableTasks);
        }
        // If idle time is negative, it means no idle time is needed
        idleTime = max(0, idleTime);
        // Total time is the sum of tasks and idle time
        return tasks.size() + idleTime;
    }
};


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0}; int maxm = 1;  //max freq == maxm
        for (char &ch: tasks) {freq[ch-'A'] ++; maxm = max(maxm, freq[ch-'A']);}
        int maxcnt = 0;
        for (int &x: freq) if (maxm == x) maxcnt++;
        return max((int)tasks.size(), ((n+1)*(maxm-1)+maxcnt)); //typecasting (size_t) into (int).
    }
};
