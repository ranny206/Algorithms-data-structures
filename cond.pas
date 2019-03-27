program cond;

var
  prop: array [0..50000] of integer;
  price: array [1..1000] of integer;
  power, d: integer;
  i, j: integer;
  n, m: integer; 
  sum, minimum: integer;

begin
  assign(input, 'cond.in');
  reset(input);
  rewrite(output, 'cond.out');
  readln(n);
  sum := 0;
  minimum := 1001;
  for i := 0 to n-1 do 
    read(prop[i]);
  readln(m);
  for i := 0 to 1000 do 
    price[i] := 1001;
  for i := 0 to m-1 do 
  begin
    readln(power, d);
    if price[power] > d then 
      price[power] := d;
  end;
  for i := 0 to n-1 do 
  begin
    for j := prop[i] to 1000 do
      if (price[j] < minimum) then
        minimum := price[j];
    sum := sum + minimum;
    minimum := 1001;
  end;
  write(sum);
  close(output);
end.


