/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef ABSTRACTANNOTATIONITEM_H
#define ABSTRACTANNOTATIONITEM_H

#include <QGraphicsItem>
#include <QPainter>

#include "AnnotationItemProperties.h"

class AbstractAnnotationItem : public QGraphicsItem
{
public:
    AbstractAnnotationItem(const AnnotationItemProperties& properties);
    ~AbstractAnnotationItem();
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    virtual void addPoint(const QPointF &position) = 0;
    virtual void moveTo(const QPointF &newPosition) = 0;
    AnnotationItemProperties properties() const;
    void setProperties(const AnnotationItemProperties& properties);

protected:
    void setShape(QPainterPath& newShape);
    virtual void updateShape() = 0;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    AnnotationItemProperties* mProperties;
    QPainterPath*             mShape;
};

#endif // ABSTRACTANNOTATIONITEM_H
