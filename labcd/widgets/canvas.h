﻿#pragma once

#include <QWidget>
#include <QScrollArea>
#include <opencv2/opencv.hpp>
#include "annotationview.h"
#include "annotationscence.h"
#include "../utils/label.h"

class Canvas : public QScrollArea
{
	Q_OBJECT

private:
	double optSize = 0.98;  // 最佳缩放
	AnnotationView* aView = nullptr;

public:
	AnnotationScence* aScene = nullptr;

	Canvas(QWidget *parent = nullptr);
	~Canvas();
	void resetZoom(int width, int height);
	void loadImageFromPixmap(QPixmap pixmap);
	void syncViewTranslate(int hPos, int vPos, QTransform tf, double zoom);
	void scroolTranslate(int hPos, int vPos);

signals:
	void syncViewRequest(int hPos, int vPos, QTransform tf, double zoom);
	void syncScroll(int hPos, int vPos);  // 滑块控制
	void setLabel(Label* label);
	void setImageSize(int imgWidth, int imgHeight);
};
