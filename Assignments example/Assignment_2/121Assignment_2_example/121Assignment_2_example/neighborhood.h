/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Class representing a neighborhood (represented as an array) of `Shape`s.
 *
 * Notes:
 * - We use `exit(1)` here for errors.  Later, we'll go over exceptions, which
 *   would be a much better solution.
 */


#ifndef NEIGHBORHOOD_H
#define NEIGHBORHOOD_H
// ----------------------------------------------------------------------------

#include "shape.h"
#include <vector>

// ----------------------------------------------------------------------------

class Shape;
/**
 * Forward declare `Shape`, in case this file gets included first.
 *
 * This is definitely not the cleanest way to do things; but it seems to me
 * right now to be the simplest.
 */

// ----------------------------------------------------------------------------

class Neighborhood {
	private:
		Shape * neighborhood_;
		/**
		 * The place where we'll store our 2D array of `Shape`s.
		 *
		 * Since we don't know how big the array will be, we can't use a
		 * regular (stack allocated) array.  In the constructor, this will be
		 * initialized to a 1D array large enough to hold all the values, and
		 * we will emulate using it as a 2D array by taking the index as
		 * ```
		 * neighborhood_[ y * size_x + x ];
		 * ```
		 * (where, if it were a real 2D array, we could have said
		 * `neighborhood_[y][x]`).
		 */

	public:
		const unsigned int size_x;
		/**
		 * The number of "columns" (x values) in `neighborhood_`.
		 */

		const unsigned int size_y;
		/**
		 * The number of "rows" (y values) in `neighborhood_`.
		 */

		Neighborhood(unsigned int size_x, unsigned int size_y);
		/**
		 * The constructor.
		 *
		 * Must initialize `size_x` and `size_y`.
		 *
		 * Must also allocate memory for `neighborhood_`, initialize it to
		 * contain all "empty" `Shape`s, and then fill it with non-empty shapes
		 * so that the ratio of non-empty to empty shapes is `RATIO_FILLED`
		 * (from `constants.h`).
		 *
		 * Notes:
		 * - Since `size_x` and `size_y` are constant, they must be initialized
		 *   in the initialization list, rather than set in the constructor
		 *   body.
		 * - You may assume that the dynamic memory allocation succeeds.
		 */

		~Neighborhood();
		/**
		 * The destructor.
		 *
		 * Must free the memory that the constructor allocated to
		 * `neighborhood_`.
		 */


		Shape get(unsigned int x, unsigned int y) const;
		/**
		 * Return the `Shape` at `neighborhood_[ y * size_x + x ]`.
		 *
		 * If `x` or `y` is out of bounds, should write
		 * ```
		 * "ERROR: `Neighborhood::get`: index out of bounds\n"
		 * ```
		 * to `cerr` and `exit(1)`.
		 */

		void set(unsigned int x, unsigned int y, const Shape & s);
		/**
		 * Set the `Shape` at `neighborhood_[ y * size_x + x ]` to `s`.
		 *
		 * If `x` or `y` is out of bounds, should write
		 * ```
		 * "ERROR: `Neighborhood::set`: index out of bounds\n"
		 * ```
		 * to `cerr` and `exit(1)`.
		 */


		void move(unsigned int old_x, unsigned int old_y);
		/**
		 * Move the shape at index `old_x, old_y` to a random empty location in
		 * the neighborhood.
		 */


		void animate(unsigned int frames);
		/**
		 * 1. Create a buffer.
		 * 2. Draw all the shapes in our neighborhood to it, and render it to
		 *    the screen.
		 * 3. Move all the unhappy shapes, and go back to step (2).
		 *
		 * Loop from step (3) to step (2) `frames` times; that is, the
		 * neighborhood should be rendered to the screen (i.e. output to the
		 * terminal) `frames` times.
		 *
		 * To make it so that each frame can be seen, you should have the
		 * program sleep for a little while (probably at least 100
		 * milliseconds) at the end of each loop.  To do this, include the
		 * `<chrono>` and `<thread>` headers, and use the following code:
		 * ```
		 * std::this_thread::sleep_for(std::chrono::milliseconds(100));
		 * ```
		 */
};

// ----------------------------------------------------------------------------
#endif

