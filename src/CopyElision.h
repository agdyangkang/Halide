#ifndef HALIDE_COPY_ELISION
#define HALIDE_COPY_ELISION

#include <map>

#include "IR.h"

/** \file
 * Defines a lowering pass that eliminates unnecessary copies.
 */

namespace Halide {
namespace Internal {

/** Find unnecessary copies and remove them from the Stmt. This doesn't touch
 * Store/Load nodes and so must be called before \ref storage_flattening. This
 * also assumes the tuples have not been split and so must be called before
 * \ref split_tuples.
 */
Stmt copy_elision(Stmt s,
                  const std::vector<std::string> &order,
                  const std::map<std::string, Function> &env);

void copy_elision_test();

}  // namespace Internal
}  // namespace Halide

#endif
