left = []
right = []

File.foreach("input.txt") do |line|
	line = line.split("   ")
	left.append(line[0].to_i)
	right.append(line[1].to_i)
end

left.sort!
right.sort!

distance = 0
similarity = 0

(left.length).times do |i|
	leftV = left[i]
	distance += (leftV - right[i]).abs

	if right.include?leftV then
		similarity += leftV*right.count(leftV)
	end
end

puts(distance)
puts(similarity)