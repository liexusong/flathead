// Boolean.c
// ---------
// Boolean properties, methods, and prototype

#include "Boolean.h"

// (new) Boolean(value)
JSValue *
bool_new(JSValue *instance, JSArgs *args, State *state)
{
  JSValue *val = ARG(args, 0);
  if (state->construct)
    fh_set(state->this, "__value__", val);
  return TO_BOOL(val);
}

// Boolean.prototype.toString()
JSValue *
bool_proto_to_string(JSValue *instance, JSArgs *args, State *state)
{
  return instance->boolean.val ? JSSTR("true") : JSSTR("false");
}

// Boolean.prototype.valueOf()
JSValue *
bool_proto_value_of(JSValue *instance, JSArgs *args, State *state)
{
  return instance;
}

JSValue *
bootstrap_boolean()
{
  JSValue *boolean = JSNFUNC(&bool_new);
  JSValue *prototype = JSOBJ();

  // Boolean
  // -------

  // Properties
  BUILTIN(boolean, "prototype", prototype);

  // Boolean.prototype
  // -----------------
  
  // Properties
  BUILTIN(prototype, "constructor", JSNFUNC(&bool_new));
  
  // Methods
  BUILTIN(prototype, "toString", JSNFUNC(&bool_proto_to_string));
  BUILTIN(prototype, "valueOf", JSNFUNC(&bool_proto_value_of));

  return boolean;
}
