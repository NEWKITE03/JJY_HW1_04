#include "Shape.h"

Shape::Shape()
{
	rotate = 0;
}

Shape::~Shape()
{
}

void Shape::draw(QPainter* painter)
{
	QTransform transform = QTransform::fromTranslate(position.x(), position.y());
	transform.rotate(rotate);
	painter->setTransform(transform);
	painter->setPen(pen);
	painter->setBrush(brush);
	onDraw(painter);
}

void Shape::rotation(double angle)
{
	rotate += angle;
}

void Shape::move(QPointF pos)
{
	position = pos;
}

void Shape::setBrush(QBrush brush)
{
	this->brush = brush;
}

void Shape::setPen(QPen pen)
{
	this->pen = pen;
}



PolygonShape::PolygonShape(QPolygonF polygon) : polygon(polygon)
{
}

PolygonShape::~PolygonShape()
{
}

void PolygonShape::onDraw(QPainter* painter)
{
	painter->drawPolygon(polygon);
}

EllipseShape::EllipseShape(QPointF size) :size(size)
{
}

EllipseShape::~EllipseShape()
{
}

void EllipseShape::onDraw(QPainter* painter)
{
	painter->drawEllipse(QPointF(), size.x(), size.y());
}

RoundedRectShape::RoundedRectShape(QPointF size, QPointF radius, Qt::SizeMode mode) :size(size), radius(radius), mode(mode)
{
}

RoundedRectShape::~RoundedRectShape()
{
}

void RoundedRectShape::onDraw(QPainter* painter)
{
	painter->drawRoundedRect(QRectF{ -size.x() / 2, -size.y() / 2, size.x(), size.y() }, radius.x(), radius.y(), mode);
}
