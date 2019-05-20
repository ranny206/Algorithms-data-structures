program statistic;

var
  a: array of int32;
  n, k, i: integer;

  function Part(l, r: integer): integer;
  var
    j, i: integer;
    x, buf: int32;
  begin
    x := a[r];
    j := l - 1;
    for i := l to r - 1 do
    begin
      if a[i] <= x then
      begin
        j := j + 1;
        buf := a[j];
        a[j] := a[i];
        a[i] := buf;
      end;
    end;
    buf := a[j + 1];
    a[j + 1] := a[r];
    a[r] := buf;
    Result := j + 1;
  end;

  function Rand_Part(l, r: integer): integer;
  var
    i: integer;
    buf: int32;
  begin
    randomize;
    i := random(r - l + 1) + l;
    buf := a[r];
    a[r] := a[i];
    a[i] := buf;
    Result := Part(l, r);
  end;

  procedure Rand_Select(l, r, k: integer);
  var
    s, q: integer;
  begin
    if l = r then
    begin
      Writeln(a[l]);
      exit;
    end;
    q := Rand_Part(l, r);
    s := q - l + 1;
    if k = s then
    begin
      Writeln(a[q]);
      exit;
    end
    else if k < s then
      Rand_Select(l, q - 1, k)
    else
      Rand_Select(q + 1, r, k - s);
  end;

begin
  Assign(input, 'input.txt');
  reset(input);
  Assign(output, 'output.txt');
  rewrite(output);
  readln(n, k);
  setlength(a, n);
  for i := 0 to n - 1 do
    a[i] := 0;
  for i := 0 to n - 1 do
    Read(a[i]);
  Rand_Select(0, n - 1, k);
  Close(output);

end.
