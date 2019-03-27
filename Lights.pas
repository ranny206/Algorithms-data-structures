program lights;

var
  meters: array [1..200] of integer;
  distance: array [1..100] of integer;
  height: array [1..100] of integer;
  i, j: integer;
  n, maximum: integer;

begin
  assign(input, 'input.txt');
  reset(input);
  rewrite(output, 'output.txt');
  read(n);
  maximum := -1;
  for i := 1 to n do 
    read(distance[i], height[i]);
  for i := 1 to n do
  begin
    for j := distance[i] - height[i] to distance[i] + height[i] - 1  do
    if (j <= 100) and (j >= 1) then 
      meters[j] := meters[j] + 1;
  end;
  for i := 1 to 100 do 
    if meters[i] > maximum then 
      maximum := meters[i];
  write(maximum);
  close(output);
end.