#include "cluenumberbutton.h"

#include <QDebug>


/**
 * Constructor
 *
 * @param b is the button's reference.
 * @param parent is the parent 'QWidget'
 */
ClueNumberButton::ClueNumberButton(int *b, QWidget *parent) : button(b), QPushButton(parent)
{
    setMinimumSize(SIZE, SIZE);
    setMaximumSize(SIZE, SIZE);
    toggled = false;
    applyBaseStyle();
}

/**
 * Catch mouse press event, then toggle style.
 *
 * @param e is the send event
 */
void ClueNumberButton::mousePressEvent(QMouseEvent *e) {
    if (e->button() != Qt::LeftButton && e->button() != Qt::RightButton) {
        return;
    }
    *(button) = e->button();

    toggleStyle();
}

/**
 * Toggle the button style.
 */
void ClueNumberButton::toggleStyle() {
    if (toggled) {
        applyBaseStyle();
    }
    else {
        applyStrikeStyle();
    }
    toggled = !toggled;
}

/**
 * Apply the "cross" style on the button.
 */
void ClueNumberButton::applyStrikeStyle() {
    this->setStyleSheet("ClueNumberButton {text-decoration: line-through; font-weight: normal; color: gray; border-radius: 0;}");
}

/**
 * Apply the "basic" style on the button.
 */
void ClueNumberButton::applyBaseStyle() {
    this->setStyleSheet("ClueNumberButton {text-decoration: none; font-weight: bold; border-radius: 0;}");
}

/**
 * Set the text content of the button.
 */
void ClueNumberButton::setText(QString text) {
    QPushButton::setText(text);
    if (isZero()) {
        toggleStyle();
    }
}

/**
 * Check if the number is zero.
 *
 * @return true if the number is zero, false otherwise.
 */
bool ClueNumberButton::isZero() {
    return (this->text() == "0");
}
