def licz(indeks)
  *, x, y = indeks.to_s.chars.map(&:to_i)
  id1 = ( x   % 5) + 3
  id2 = ( y   % 5) + 8
  id2 = (((y+1)% 5) + 8) if id1 == id2
  puts("ID1 = #{id1}, ID2 = #{id2}")

end
# licz(182619)
# ID1 = 4, ID2 = 12
