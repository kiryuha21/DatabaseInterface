# frozen_string_literal: true

require 'faker'

file = File.open('/media/sf_win_lin/territory_data_script.sql', 'w')
file.write("INSERT INTO territory_data (id, region, city, district) values\n")
99.times do |i|
  file.write("(#{i + 1}, #{rand(1..100)}, '#{Faker::Address.city}', '#{Faker::Address.street_name.gsub("'", "''")}'),\n")
end
file.write("(100, #{rand(1..100)}, '#{Faker::Address.city}', '#{Faker::Address.street_name.gsub("'", "''")}');\n")
file.close
