# 智能蛇实验报告

## 一、编译并运行 sin-demo.c

![](http://m.qpic.cn/psb?/V10TJRfP2sMibY/nvCwZBwdnwnrB0mnluAYaxADV27tvTnxZC6A*H0Lgns!/b/dFMBAAAAAAAA&bo=2QKwAQAAAAACN3k!&rf=viewer_4)

## 二、将贪吃蛇的代码加入
 
![](http://m.qpic.cn/psb?/V10TJRfP2sMibY/GGR4kYvhJ9mNqwLpJ*MoAaB3RMihDZUtix3h7yNzW1g!/b/dFQBAAAAAAAA&bo=kgbOAwAAAAACN0o!&rf=viewer_4)


## 三、编写智能算法

### 1.请修改初始化字符矩阵，或者通过文件读入地图。地图中有一些你设定的障碍物（墙），效果如下：

![](http://m.qpic.cn/psb?/V10TJRfP2sMibY/16OSpGaAtf1hOgj*k8jZ9UiX.9hoyXUaiOBSLjvHRTA!/b/dDMBAAAAAAAA&bo=IQVwAwAAAAACN0Q!&rf=viewer_4)

### 2.请实现如下算法决定蛇行走的方向

### 伪代码如下：

```
输出字符矩阵
WHILE not 游戏结束 DO
    wait(time)
    ch＝whereGoNext(Hx,Hy,Fx,Fy)
    CASE ch DO
    ‘A’:左前进一步，break 
    ‘D’:右前进一步，break    
    ‘W’:上前进一步，break    
    ‘S’:下前进一步，break    
    END CASE
    输出字符矩阵
END WHILE
输出 Game Over!!! 
```

### 3.思考：一个长度为5的障碍物能困死该自动跑的蛇吗？  

有可能，比如：

![](http://m.qpic.cn/psb?/V10TJRfP2sMibY/xZTPniibOmrG.SCecnqZbKMkwHXXLlEGpv5.YRBnejg!/b/dFMBAAAAAAAA&bo=OgIJAgAAAAACJzA!&rf=viewer_4)


# 总结。  
  
 本次学习如何制作智能蛇，实在上次的贪吃蛇的基础上更进一步的实验。想要完成这些目标，首先需要对该项目进行分解，把所需的规划好，分别来实现。     还有至于新的编译环境 linux 系统的稍显卡顿真的让新手有些吃不消，它与 win10 编译环境的不一样也导致一些代码不能在 win10 上运行。不过经过这次实验，我大概摸着了linux的一点门道，对以后的使用算是做了个铺垫。  
  伪代码的存在非常重要，它体现了整个程序的思路，只有有清晰的思路方能更准确有效地完成任务。 虽然对于最后的智能蛇一块，上述的伪代码所体现的思想并不能完全使这条蛇变得非常“聪明”，就比如说它变得十分长的时候经常会吃到自己。但总的来说，体现了自顶向下，逐步求精的分步构建工程的思想。

