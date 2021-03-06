#include "rlang.h"

bool r_as_bool(SEXP x) {
  if (r_kind(x) != LGLSXP && r_length(x) != 1)
    r_abort("Expected a scalar logical");
  int* xp = (int*) LOGICAL(x);
  return *xp;
}

int r_as_optional_bool(SEXP lgl) {
  if (lgl == r_null) {
    return -1;
  } else {
    return r_as_bool(lgl);
  }
}

bool r_is_true(SEXP x) {
  if (r_kind(x) != LGLSXP || r_length(x) != 1) {
    r_abort("`x` must be a boolean");
  }

  int value = LOGICAL(x)[0];
  return value == NA_LOGICAL ? 0 : value;
}
