#!/usr/bin/ruby
require 'bigdecimal'

amounts  =  gets
b = amounts.split(" ");
transamount = Integer(b[0] )
totalamount = Float(b[1])
if (transamount % 5 == 0 and transamount > 4)
	if (totalamount - transamount -0.50) > 0
		totalamount = totalamount - transamount
		totalamount = totalamount - 0.50
	end
end
puts totalamount

