var checkStraightLine = function (coordinates) {
  var [[x0, y0], [x1, y1]] = coordinates,
    slope = (y1 - y0) / (x1 - x0);

  return (
    coordinates.every(([x, y], i) => (y - y0) / (x - x0) === slope || !i) ||
    coordinates.every(([x, _]) => x == x0)
  );
};