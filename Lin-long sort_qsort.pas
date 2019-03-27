program lin_long_sort;

type TArr = array [1..10000000] of integer;

var
  num: TArr;
  n: integer;
  min, max, medium: integer;
  i: integer;

procedure quick_sort(var num: TArr; max, min: integer);
var
  help: integer;
  extra_max, extra_min: integer;
  medium: integer;
begin
  extra_max := max;
  extra_min := min;
  medium := num[(extra_max + extra_min) div 2];
  repeat 
    while num[extra_max] > medium do 
      extra_max := extra_max - 1;
    while num[extra_min] < medium do 
      extra_min := extra_min + 1;
    if (extra_min <= extra_max) then
        begin
          help := num[extra_min];
          num[extra_min] := num[extra_max];
          num[extra_max] := help;
          extra_max := extra_max - 1;
          extra_min := extra_min + 1;
        end;
  until extra_min > extra_max;
  if min < extra_max then quick_sort(num, extra_max, min);
  if extra_min < max then quick_sort(num, max, extra_min);
end;

begin
 assign(input, 'input.txt');
 reset(input);
 rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do 
    read(num[i]);
  max := n;
  min := 1;
  quick_sort(num, max, min);
  for i := 1 to n do 
    write(num[i], ' ');
 close(output)
end.



