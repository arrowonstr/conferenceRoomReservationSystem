# conferenceRoomReservationSystem
会议室预约系统

## 一.环境
该系统使用C++ QT开发，使用方法：
1. 下载代码
2. 将所有head、source中文件取出和其他文件放在同一目录下
3. 使用QT软件打开项目打开.pro文件
4. 配置对应数据库，具体数据库内容见本文 二. ，或修改代码符合自己的数据库
5. 运行
## 二.系统流程图

![流程图](https://github.com/arrowonstr/conferenceRoomReservationSystem/blob/master/imgs/conference.png)
其中：
1. 大矩形框代表界面
2. 正方形框代表按钮
3. 小矩形框代表下拉式选项
4. 实线箭头代表按钮按下后打开/更新某一界面
5. 虚线箭头代表按钮按下后向调用数据库

流程图仅表示大致流程，许多细节是被隐藏的，具体可以看代码

## 三.数据库配置
数据库需要配置为下面对应配置，或者修改mycfsql.cpp文件中的`createConnectionByName`函数，以及signwindow.cpp构造函数中`cf.createConnectionByName("conference")`数据库名
表需要完全相同配置
### 1.数据库
服务器：本地
数据库名：conference
用户名：root
密码：1234
端口号：3306

### 2.表
#### 2.1 conference_users
|字段名称|数据类型|是否为可空|默认值|含义|
|:---:|:---:|:---:|:---:|:---:|
|users_id       | int         | NO   |  NULL    |id| 
| users_name     | varchar(20) | NO   |NULL    |用户名|                
| users_password | varchar(20) | NO   |NULL    |密码|                
| users_author   | int         | NO   |NULL    |权限|

其中：
users_id为主键
权限 0为用户 1为管理员             
#### 2.2 conference_rooms
|字段名称|数据类型|是否为可空|默认值|含义|
|:---:|:---:|:---:|:---:|:---:|
 rooms_id       | int         | NO   |  NULL    | id|
| rooms_name     | varchar(20) | NO   | NULL    | 名称|               
| rooms_number   | int         | NO   | NULL    | 房号|           
| rooms_capacity | int         | NO   |NULL    | 最大人数|               
| rooms_square   | int         | NO   |NULL    |面积|                
| rooms_describe | varchar(50) | NO   |NULL    |描述|                
| rooms_reserve  | varchar(12) | NO   | NULL   |无|

其中：
rooms_id为主键
rooms_reserve为废弃的字段 但是不想改代码了 所以保留在这里 其没有含义和作用

#### 2.3 conference_reserves
|字段名称|数据类型|是否为可空|默认值|含义|
|:---:|:---:|:---:|:---:|:---:|
|reserves_id | int| NO | NULL|id|
| reserves_user     | varchar(20) | NO   |NULL|预约用户|
| reserves_number   | int         | NO   |NULL|预约房号|
| reserves_stime    | datetime    | NO  |NULL|开始时间|
| reserves_etime    | datetime    | NO  |NULL|结束时间|
| reserves_subject  | varchar(20) | NO   |NULL|主题|
| reserves_capacity | int         | NO   |NULL|人数|
| reserves_state    | int         | NO   |NULL|状态|
| reserves_describe | varchar(50) | NO   |NULL|描述|

其中：
reserves_id为主键
状态 0未审批 1未审批 2为驳回 3为取消
