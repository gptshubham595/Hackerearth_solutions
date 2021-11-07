/*I recently came across a question . The question was like
You are given a straight line statring at 0 to 10^9. You start at zero and there are n tasks you can perform. ith task is located at point 'i' in the line and requries 't' time to be performed. To perform the task you need to reach the ppoint 'i' and spend 't' time at that location. e.g (5,8) lies at 5 so travel distance is 5 and work effort is 8.
Total effort is calculated as travel distance + time required to complete the work.

It takes one sec to travel one unit of path.

Now we are given total T seconds and we need to complete as many tasks as possible and reach back to starting position
Find the max number of tasks that you can finish in time T.
e.g
3 16 -> 3 tasks and 16 units of total time
2 8 -> task 1 at position 2 in line and takes 8 sec to complete
4 5 -> task 2 at position 4 in line and takes 5 sec to complete
5 1 -> task 3 at position 5 in line and takes 1 sec to complete
​​​​​​​
Output : 2

Explanation :
If we take task 1 at location 2 which requires 8 sec then getting to location 2 takes 2s and completing the task takes 8s leaving us with only 6s which is not enough for completing other task
*/

```
int solve(int n,int t,vector<vector >task){

  sort(task.begin(),task.end());
  multiset<int>s;
  long long sum=0;
  int ans=0;

  for(int i=0;i<n;i++){
        sum+=1LL*task[i][1];
        s.insert(-task[i][1]);
        long long time = 2LL*task[i][0];
        while(!s.empty() && sum+time>1LL*t){
              sum+=1LL*(*s.begin());
              s.erase(s.begin());
        }
        ans=max(ans,(int)s.size());
  }

  return ans;
}
```
