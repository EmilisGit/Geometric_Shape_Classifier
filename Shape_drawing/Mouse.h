#pragma once
#include <SDL.h>

/**
 * @class Mouse
 * @brief Handles the input from the mouse
 */
class Mouse {
private:
    bool mousedown = false; ///< Indicates whether the mouse is currently pressed down
    bool leftButtonPressed = false; ///< Indicates whether the left mouse button is currently pressed
    bool leftButtonReleased = false; ///< Indicates whether the left mouse button was released

public:
    /**
     * @brief Default constructor for the Mouse class
     */
    Mouse() {}

    /**
     * @brief Getter for the mousedown state
     * @return True if the mouse is currently pressed down, false otherwise
     */
    bool getMousedown() const { return mousedown; }

    /**
     * @brief Setter for the mousedown state
     * @param state The new mousedown state to set
     */
    void setMousedown(bool state) { this->mousedown = state; }

    /**
     * @brief Retrieves the current state of the mouse buttons
     * @param x Reference to the x-coordinate of the mouse position
     * @param y Reference to the y-coordinate of the mouse position
     * @return The current state of the mouse buttons
     */
    Uint32 getMouseState(int& x, int& y);

    /**
     * @brief Getter for the leftButtonPressed state
     * @return True if the left mouse button is currently pressed, false otherwise
     */
    bool getLeftButtonPressed() const { return leftButtonPressed; }

    /**
     * @brief Setter for the leftButtonPressed state
     * @param pressed The new leftButtonPressed state to set
     */
    void setLeftButtonPressed(bool pressed) { leftButtonPressed = pressed; }

    /**
     * @brief Getter for the leftButtonReleased state
     * @return True if the left mouse button was released, false otherwise
     */
    bool getLeftButtonReleased() const { return leftButtonReleased; }

    /**
     * @brief Setter for the leftButtonReleased state
     * @param released The new leftButtonReleased state to set
     */
    void setLeftButtonReleased(bool released) { leftButtonReleased = released; }
};
