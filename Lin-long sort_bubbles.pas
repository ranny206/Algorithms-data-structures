program lin_long_sort;

var
  num: array [1..10000] of integer;
  i, j: integer;
  n: integer;
  help: integer;

begin
assign(input, 'input.txt');
reset(input);
rewrite(output, 'output.txt');
  read(input, n);
  for i := 1 to n do
    read(input, num[i]);
  for i := 1 to n - 1 do
    for j := 1 to n - i do
      if num[j] > num[j + 1] then 
      begin
        help:= num[j+1];
        num[j+1]:= num[j];
        num[j]:=help;
      end;
  for i := 1 to n do
    write(num[i], ' ');
close(output);
end.
                      