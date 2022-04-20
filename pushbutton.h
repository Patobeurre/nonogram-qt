#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMouseEvent>
#include <QMimeData>

#define SIZE 20     ///< The fixed size of the button.


/**
 * Implementation of a customized 'QPushButton' for puzzle squares.
 *
 * Each puzzle square is made clickable. They can be marked as
 * empty, fill or dot.
 *
 * @author Patobeur
 */
class PushButton : public QPushButton {
    Q_OBJECT

 private:
    /// The button reference
    int *button;
    /// Is true if this is the first button pressed on drag action.
    bool *first;
    /// Is true when the drag action is initiated.
    bool processed;

 public:
    /// Constructor
    PushButton(int *b, bool *f, QWidget *parent = 0);

 protected:
    /// Event handler for mouse drag
    void dragEnterEvent(QDragEnterEvent *e);
    /// Event handler for button clicked
    void mousePressEvent(QMouseEvent *e);

 signals:
    /// Signal emitted to set the square to fill
    void solid();
    /// Signal emitted to set the square to dot
    void dot();
};
#endif

