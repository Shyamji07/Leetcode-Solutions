var finalString = function (s) {
  let a = []
  for (let e of s) {
    if (e === 'i') {
      a.reverse()
    } else {
      a.push(e)
    }
  }
  return a.join("")
};
