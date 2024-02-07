class Solution { public:
int lastStoneWeight(vector<int>& stones)
{
int a,b; priority_queue<int>pq;
for(int i=0;i<stones.size();i++) pq.push(stones[i]);
  while(pq.size()!=1){
     		a=pq.top();
pq.pop();
b=pq.top();
pq.pop(); int c=a-b; pq.push(c);
}
return pq.top();
}
};
