#!/usr/bin/ruby
a = 0
while a != 42 do
	a =	gets
	if Integer(a) == 42
     break
	end
	puts a
end
