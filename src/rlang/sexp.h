#ifndef RLANG_SEXP_H
#define RLANG_SEXP_H

#include <stdbool.h>


static inline SEXPTYPE r_length(SEXP x) {
  return Rf_length(x);
}

static inline SEXPTYPE r_kind(SEXP x) {
  return TYPEOF(x);
}

static inline bool r_inherits(SEXP x, const char* class_) {
  return Rf_inherits(x, class_);
}

static inline SEXP r_get_attribute(SEXP x, SEXP sym) {
  return Rf_getAttrib(x, sym);
}

static inline void r_poke_attribute(SEXP x, SEXP sym, SEXP value) {
  Rf_setAttrib(x, sym, value);
}
static inline void r_poke_class(SEXP x, SEXP classes) {
  Rf_setAttrib(x, R_ClassSymbol, classes);
}

SEXP r_set_attribute(SEXP x, SEXP sym, SEXP attr);

static inline SEXP r_set_class(SEXP x, SEXP classes) {
  return r_set_attribute(x, R_ClassSymbol, classes);
}

static inline SEXP r_get_class(SEXP x) {
  return Rf_getAttrib(x, R_ClassSymbol);
}
static inline SEXP r_names(SEXP x) {
  return Rf_getAttrib(x, R_NamesSymbol);
}

static inline void r_poke_names(SEXP x, SEXP nms) {
  Rf_setAttrib(x, R_NamesSymbol, nms);
}

bool r_has_name_at(SEXP x, r_size_t i);
bool r_is_named(SEXP x);

static inline SEXP r_missing_arg() {
  return R_MissingArg;
}
static inline bool r_is_missing(SEXP x) {
  return x == R_MissingArg;
}

static inline bool r_is_null(SEXP x) {
  return x == R_NilValue;
}

static inline SEXP r_duplicate(SEXP x, bool shallow) {
  if (shallow) {
    return Rf_shallow_duplicate(x);
  } else {
    return Rf_duplicate(x);
  }
}

static inline bool r_is_object(SEXP x) {
  return OBJECT(x);
}

static inline SEXP r_poke_kind(SEXP x, SEXPTYPE kind) {
  SET_TYPEOF(x, kind);
  return x;
}
static inline SEXP r_poke_str_kind(SEXP x, const char* type) {
  SET_TYPEOF(x, Rf_str2type(type));
  return x;
}

static inline const char* r_type_c_string(SEXPTYPE kind) {
  SEXP str = Rf_type2str(kind);
  return CHAR(str);
}

static inline bool r_is_symbolic(SEXP x) {
  return
    r_kind(x) == LANGSXP ||
    r_kind(x) == SYMSXP;
}


#endif
