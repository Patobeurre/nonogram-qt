#ifndef CLUENUMBERBUTTON_H
#define CLUENUMBERBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

#define SIZE 20     ///< The fixed size of the button.


/**
 * @brief Implementation of a customized 'QPushButton' for clue numbers.
 *
 * Each clue number on the puzzle's side is made clickable.
 * It allows the user to cross any number.
 *
 * @author Patobeur
 */
class ClueNumberButton : public QPushButton
{
    Q_OBJECT

private:
    /// The button reference.
    int *button;
    /// Is true if the clue number is crossed, false otherwise.
    bool toggled;

    /// Change the button's style to cross style.
    void applyStrikeStyle();
    /// Change the button's style to base style.
    void applyBaseStyle();
    /// Set button style according to 'toggled' value.
    void toggleStyle();

public:
    /// Constructor
    ClueNumberButton(int *b, QWidget *parent = 0);

    /// Set button's text content.
    void setText(QString text);
    /// Check if the number is zero.
    bool isZero();

protected:
    /// Event handler for button press
    void mousePressEvent(QMouseEvent *e);

};

#endif // CLUENUMBERBUTTON_H
