#include "JJY_HW1_04.h"

#include <qrandom.h>
#include <random>

JJY_HW1_04::JJY_HW1_04(QWidget* parent)
	: QMainWindow(parent)
{
    ui.setupUi(this);


	std::random_device device;
	QRandomGenerator generator(device());
	for (size_t i = 0; i < 100; i++)
	{
		shapes.push_back(new PolygonShape(QPolygonF({ {-100 * generator.generateDouble(),-100 * generator.generateDouble()}, {100 * generator.generateDouble(),-100 * generator.generateDouble()},
			{100 * generator.generateDouble(),100 * generator.generateDouble()}, {-100 * generator.generateDouble(),100 * generator.generateDouble()}, })));
		shapes.push_back(new RoundedRectShape({ 200 * generator.generateDouble(),100 * generator.generateDouble() }, { 10 * generator.generateDouble(),20 * generator.generateDouble() }));
		shapes.push_back(new EllipseShape({ 200 * generator.generateDouble(),200 * generator.generateDouble() }));
	}
}

JJY_HW1_04::~JJY_HW1_04()
{}

void JJY_HW1_04::paintEvent(QPaintEvent* event)
{
	QPainter painter;
	painter.begin(this);
	for (auto& i : shapes)
	{
		i->draw(&painter);
	}

	painter.end();
}

void JJY_HW1_04::resizeEvent(QResizeEvent* event)
{
	std::random_device device;
	QRandomGenerator generator(device());
	for (auto& i : shapes)
	{
		i->move({ width() * generator.generateDouble(),height() * generator.generateDouble() });
		i->rotation(360 * generator.generateDouble());
		i->setBrush(QBrush(QColor(255 * generator.generateDouble(), 255 * generator.generateDouble(), 255 * generator.generateDouble())));
		i->setPen(QPen(QColor(255 * generator.generateDouble(), 255 * generator.generateDouble(), 255 * generator.generateDouble()), 5 * generator.generateDouble()));
	}
	update();
}
