/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Class representing a shape (triangle or square) with biases about what kinds
 * of shapes it wants for neighbors.
 */

#ifndef SHAPE_H
#define SHAPE_H
// ----------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "buffer.h"
#include "neighborhood.h"

// ----------------------------------------------------------------------------

class Neighborhood;
/**
 * Forward declare `Neighborhood`, in case this file gets included first.
 *
 * This is definitely not the cleanest way to do things; but it seems to me
 * right now to be the simplest.
 */

// ----------------------------------------------------------------------------

class Shape {
	private:
		std::string type_;
		/**
		 * A string representing the "type" of the `Shape` (either "empty",
		 * "triangle", or "square").
		 *
		 * Notes:
		 * - It would be more "object oriented" to have separate `Empty`,
		 *   `Triangle`, and `Square` types derived from this class.  But I
		 *   decided that the complexity that introduced to the design wasn't
		 *   worth it for this project.  Also, it's nice to try this method
		 *   out, since it is a completely valid way to do things, and
		 *   sometimes it turns out to be the best.  And don't worry: we'll get
		 *   plenty of practice with inheritance later on.
		 */

		std::string type_art_;
		/**
		 * The ASCII art representing the type in `type_`.
		 *
		 * This should be set along with `type_` by the `setType` member
		 * function.
		 *
		 * You may make your own ASCII art for each type, or you may use
		 * - empty
		 *   ```
		 *   "     \n"
		 *   "     \n"
		 *   "     \n"
		 *   ```
		 * - triangle
		 *   ```
		 *   "  ,  \n" 
		 *   " / \\ \n"
		 *   "/___\\\n"
		 *   ```
		 * - square
		 *   ```
		 *   ".---.\n"
		 *   "|   |\n"
		 *   "'---'\n"
		 *   ```
		 *
		 * Make sure that the number of rows and columns is the same for each
		 * shape, and that it matches `size_x` (for columns) and `size_y` (for
		 * rows).
		 */


	public:
		static const unsigned int size_x = 5;  // must match actual size
		/**
		 * The number of columns (x values) in each ASCII art shape (each
		 * possible value of `type_art_`).
		 */

		static const unsigned int size_y = 3;  // must match actual size
		/**
		 * The number of rows (y values) in each ASCII art shape (each possible
		 * value of `type_art_`).
		 */


		Shape(const std::string & type = "empty");
		/**
		 * The constructor.
		 *
		 * Must initialize `type_`, and `type_art_`.
		 *
		 * Notes:
		 * - I suggest calling `setType` in the body of the constructor, to
		 *   avoid duplicating code.
		 */

		~Shape();
		/**
		 * The destructor.
		 *
		 * Since there's no dynamically allocated memory to `delete`, this may
		 * be left out, or it may be implemented with
		 * ```
		 * Shape::~Shape() = default;
		 * ```
		 * (valid since C++ 11).
		 */


		std::string getType();
		/**
		 * Return `type_`.
		 */

		void setType(const std::string & type);
		/**
		 * Set `type_` to `type`, and set `type_art_` to the appropriate value.
		 *
		 * If the passed `type` is not valid, write
		 * ```
		 * "ERROR: `Shape::setType`: invalid type\n"
		 * ```
		 * to `cerr` and `exit(1)`.
		 */


		void drawToBuffer(Buffer & b, unsigned int x, unsigned int y) const;
		/**
		 * Draw `type_art_` onto the `Buffer` at position `x, y`.
		 *
		 * Notes:
		 * - This (primarily) is what 
		 *   ```
		 *   void Buffer::set(unsigned int, unsigned int, std::string);
		 *   ```
		 *   is for.
		 */


		bool isHappy(const Neighborhood & n, unsigned int pos_x,
			unsigned int pos_y) const;
		/**
		 * Return `true` if the shape is happy (i.e. not willing to move), and
		 * `false` otherwise.
		 *
		 * - More specifically, return `true` if and only if the shape
		 *     - has more than 0 "triangle" or "square" neighbors
		 *     - and the ratio of like neighbors to unlike (different)
		 *       neighbors is greater than or equal to `RATIO_ALIKE_HAPPY`
		 *       (from `constants.h`)
		 *     - and the ratio of unlike (different) neighbors to like
		 *       neighbors is greater than or equal to `RATIO_DIFFERENT_HAPPY`
		 *       (from `constants.h`)
		 *
		 * Notes:
		 * - Use `n.get(...).getType() == "..."` to determine the type of the
		 *   `Shape` at a given position.
		 * - Be careful not to look for neighbors outside the bounds of the
		 *   `Neighborhood`.
		 * - Be careful not to have a shape count itself, when trying to count
		 *   its neighbors.
		 * - Be careful not to count "empty" shapes as unlike (different)
		 *   shapes ("empty" shapes should not count as either like or
		 *   unlike).
		 * - Be careful of possible division by 0 when testing the ratios of
		 *   like and unlike shapes.
		 */
};

// ----------------------------------------------------------------------------
#endif

