# 最小生成树的Prim算法
## 基本思路
  设图G=(V,E)所有顶点的集合为V，MST中顶点的集合为T
 1. 先从G中选取任意顶点r作为MST的根，将其添加到T
 2. 循环执行以下处理：
 > 1. 更新V-T中与新加入T中的节点相邻的节点的权值
 > 2. 在连接T内顶点与V-T内顶点的边中选取权值最小的边，将其作为MST的边，并将u添加到T

## 算法的实现
### 一些必备的向量
变量名 | 含义
---|---
color[n] | color[v]用于记录节点v的访问状态 WHITE/GRAY/BLACK
M[n][n] | 邻接矩阵，M[u][v]中记录u到v的边的权值
d[n] | d[v]用于记录连接T内顶点与V-T内顶点的边中，权值最小的边的权值
p[n] | p[v]用于记录MST中顶点v的父节点

### 伪代码实现
```
prim()
   将所有顶点u的color[u]设为WHITE，d[u]初始化为INFTY
   d[0] = 0
   p[0] = -1
  
  while true
     //挑选边权值最小的顶点加入T中
     mincost = INFTY
     for i from 0 to n-1
        if color[i] != BLACK && d[i] < mincost
           mincost = d[i]
           u = i
           
     if mincost == INFTY  //如果找不到符合要求的顶点，意味着所有的顶点全部加入T中了
        break;
        
     color[u] = BLACK  //状态更新
     
     //更新V-T中与新加入T中的节点相邻的节点的权值
     for v from 0 to n-1
        if color[v] != BLACK 且 u和v之间存在边
           if M[u][v] < d[v]
              d[v] = M[u][v]
              p[v] = u
              color[v] = GRAY
```

### 备注
  在使用邻接矩阵实现的Prim算法中，我们需要遍历图的所有顶点来确定d最下的顶点u，且整个算法的遍历次数与顶点树相等，因此算法复杂度为O(|V|^2). 
  如果使用二叉堆来选定顶点，Prim算法的效率将会大大提高. 
