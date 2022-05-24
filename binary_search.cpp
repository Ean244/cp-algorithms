// returns the last x in the range [lo,hi] such that f(x) = true
ll lastTrue(ll lo, ll hi, function<bool(ll)> f) {
  for (--lo; lo < hi;) {
    ll mid = lo + (hi - lo + 1) / 2;
    if (f(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;
}

// returns the first x in the range [lo,hi] such that f(x) = true
ll firstTrue(ll lo, ll hi, function<bool(ll)> f) {
  for (hi++; lo < hi;) {
    ll mid = lo + (hi - lo) / 2;
    if (f(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}