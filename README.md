# LabCD



遥感变化检测标注工具，设计参考[EISeg](https://github.com/PaddlePaddle/PaddleSeg/tree/release/2.6/EISeg)。该项目目前为自己（小白）学习C++和Qt的练习项目。

## 环境及依赖

- Visual Studio 2019

- Qt 6.4.0

- OpenCV 4.5.5

- ~~GDAL 3.5.3~~

## TODO

- [x] 完成基本界面
- [x] 基本完成数据列表功能，实现加载文件、点击跳转
- [x] 初步完成标签列表，实现标签添加、修改
- [x] 实现左右同步画布交互
- [x] 添加qmake
- [ ] 增加选择标签画多边形
  - [x] 左右画布同步画多边形
  - [ ] 左右画布同步删除顶点（无法同步删除）
  - [x] 左右画布同步移动顶点
  - [x] 左右画布同步点击边新建顶点
  - [x] 左右画布同步激活
  - [ ] 左右画布同步选择（有点BUG）
  - [ ] 左右画布同步颜色设置
- [ ] 增加保存标注结果
- [ ] 增加标签的导入导出
- [ ] 增加项目管理功能，可以反复标注一个项目
- [ ] 增加对tif的支持，保存结果带有坐标
- [ ] 增加大图自动切块
- [ ] 增加一个变化检测的参考图方便定位
- [ ] 完善工具栏和快捷键
- [ ] 打包

## 资源

- 图标：[SuperMap GIS产品彩色系功能图标库](https://www.iconfont.cn/collections/detail?spm=a313x.7781069.1998910419.d9df05512&cid=32519)
- 标签预定义颜色：[色板 | AntV](https://antv.vision/zh/docs/specification/language/palette)
