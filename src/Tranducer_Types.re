module Naive = {
  type transduce('a, 'b, 'c) =
    (~xform: ('a, 'b, 'c) => 'b, ~f: 'a, ~init: 'b, list('c)) => 'b;
  type xmap('a, 'b, 'c, 'd) = ('a => 'b, ('c, 'b) => 'd, 'c, 'a) => 'd;
  type xfilter('a, 'b, 'bool) = ('a => bool, ('b, 'a) => 'b, 'b, 'a) => 'b;

  type compose('a, 'b, 'c) = ('a => 'b, 'c => 'a, 'c) => 'b;
  type conj('a) = (list('a), 'a) => list('a);
  type xlist('a, 'b, 'c) =
    (
      ~xform: ((list('a), 'a) => list('a), list('b), 'c) => list('b),
      ~init: list('b)=?,
      list('c)
    ) =>
    list('b);
};

type inc = int => int;
type unwrap_optional = option(int) => int;
type filter_numbers('a) =option('a) => bool;
type maybe_numbers =list(option(int));
type xf = 
  ((list(int), int) => list(int), list(int), option(int)) => list(int);
type only_incremented_numbers =list(int);
type reducingFn('r, 'a) =
  | Reducer(('r, 'a) => 'r): reducingFn('r, 'a);
type transducer('a, 'b) = {
  t: 'r. reducingFn('r, 'b) => reducingFn('r, 'a),
};