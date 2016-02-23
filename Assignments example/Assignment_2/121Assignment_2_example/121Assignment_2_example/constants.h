/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Global constants.
 *
 *
 * Notes:
 * - These could also be declared static, but namespaces are the more C++ way
 *   of doing things.  The goal here is to make it so that if these identifiers
 *   end up in more than one translation unit, linking doesn't fail due to
 *   their redefinition.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H
// ----------------------------------------------------------------------------

/**
 * Notes:
 * - If you like, you can start reading about what this "unnamed `namespace`"
 *   is for [here](http://www.comeaucomputing.com/techtalk/#nostatic).
 */
namespace {

    const unsigned int TERM_SIZE_X = 80;
    /**
     * The width of the terminal window, in characters.
     */

    const unsigned int TERM_SIZE_Y = 25;
    /**
     * The height of the terminal window, in characters.
     */


    const double RATIO_FILLED = 0.40;
    /**
     * How much of the neighborhood should be filled with shapes?
     */


    const double RATIO_ALIKE_HAPPY = 1 / 2.0;
    /**
     * "I'll move if my neighbors aren't at least this much like me"
     */

    const double RATIO_DIFFERENT_HAPPY = 1 / 5.0;
    /**
     * "I'll move if my neighbors aren't at least this much different than me"
     */

}

// ----------------------------------------------------------------------------
#endif

