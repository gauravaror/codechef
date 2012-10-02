#!/usr/bin/ruby
#array code
puts "Array"
array =  ["Gaurav",10,100.99,"which team you are in","element"]
array.each do |i|
	puts i
end
#Hash code
print "HASH" 
hsh = { "red" => 0x00f , "green" => 0x01f}
hsh.each do |key,value|
	puts "Color " + key + " have value " +  value.to_s() ,"\n"
end

for i in 1...10
print i," "
end

puts "Iterator"

pres = ["A","B","C","D","E"];
pres.each {|prez| print prez}
