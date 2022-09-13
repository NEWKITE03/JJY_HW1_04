#pragma once
#include <qpainter.h>


class Shape
{
public:
	Shape();
	~Shape();

protected:
	QPointF position;
	double rotate;
	QBrush brush;
	QPen pen;

public:
	void draw(QPainter* painter);
	void rotation(double angle);
	void move(QPointF pos);
	void setBrush(QBrush brush);
	void setPen(QPen pen);
protected:
	virtual void onDraw(QPainter* painter) = 0;
};


class PolygonShape :public Shape
{
public:
	PolygonShape(QPolygonF polygon);
	~PolygonShape();


protected:
	virtual void onDraw(QPainter* painter) override;
private:
	QPolygonF polygon;

};

class EllipseShape :public Shape
{
public:
	EllipseShape(QPointF size);
	~EllipseShape();


protected:
	virtual void onDraw(QPainter* painter) override;
private:
	QPointF size;
};


class RoundedRectShape :public Shape
{
public:
	RoundedRectShape(QPointF size, QPointF radius, Qt::SizeMode mode = Qt::SizeMode::AbsoluteSize);
	~RoundedRectShape();


protected:
	virtual void onDraw(QPainter* painter) override;
private:
	QPointF size;
	QPointF radius;
	Qt::SizeMode mode;
};