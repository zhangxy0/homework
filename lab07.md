# HTML5游戏设计与制作
## 游戏策划
内容介绍：操控炮台发射子弹击毁下落物。    
玩法介绍：通过键盘的左右键控制炮台的移动，通过空格键控制子弹的发射，若是被下落物击中或错过的下落物超过三个则游戏失败。  
人设：  
1.炮台：可左右移动，可发射子弹。  
2.子弹：想要击毁下落物体的必备物。  
3.下落物：决定游戏是否继续的关键，若是炮台被下落物击中或错过的下落物超过三个则游戏失败，否则游戏继续。    

![images](http://m.qpic.cn/psb?/V10JZWde3GxqHO/h4AvEyw2Pf2uGuGSbZGptmAah3H64hrCjCGCwRBLoKk!/b/dDYBAAAAAAAA&bo=oABoAAAAAAACF*s!&rf=viewer_4)  

## 游戏设计
这是一个非常简单易懂的小游戏，其中涉及到的人物及其之间的关系也十分的简单。  
1) Object:炮台  
   Attribute:图片,位置 
   Collaborator：子弹 Events & Actions：发射子弹    
2) Object:子弹  
   Attribute:图片,位置  
   Collaborator：下落物 Events & Actions：碰撞 & 销毁自己   
3) Object:下落物  
   Attribute:图片,位置  
   Collaborator：子弹 Events & Actions：碰撞 & 销毁自己
