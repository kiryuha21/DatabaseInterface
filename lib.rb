def get_names
  file = File.open('/media/sf_win_lin/entity_script.sql', 'r')
  arr = file.readlines
  file.close
  names = []

  (1..100).each do |i|
    first = arr[i].index("'")
    names.push arr[i][first + 1..arr[i][(first + 1)..].index("'") + 1]
  end

  names
end

def get_term(object_num, arr)
  num = "(#{object_num}"
  arr.select { |x| x[0] == num }.first.reject { |x| Date._parse(x).empty? }[-2..-1]
end
