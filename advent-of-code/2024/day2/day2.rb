safeReports = 0

File.foreach("input.txt") do |line|
    line = line.split(" ")
    diff = line[1] - line[0]
  
    increasing = false
    if diff == 0 then
        next
    elsif diff > 0 then
        increasing = true
    end

    safe = true
  
    (line.length-1).times do |i|
        diff = line[i+1] - line[i]
        if increasing and diff < 0 then
            safe = false
        end
        if not increasing and diff > 0 then
            safe = false
        end
    end

    if safe then
        safeReports += 1
    end
end

puts(safeReports)
