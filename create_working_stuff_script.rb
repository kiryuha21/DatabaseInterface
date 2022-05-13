# frozen_string_literal: true

require 'faker'

file = File.open('/media/sf_win_lin/working_stuff_script.sql', 'w')
file.write("INSERT INTO working_stuff (id, name, surname, specialization, salary, team_id) values\n")
9_999.times do |i|
  file.write("(#{i + 1}, '#{Faker::Name.first_name}', '#{Faker::Name.last_name.gsub("'", "''")}', '#{Faker::IndustrySegments.sub_sector}', #{rand(50_000..150_000)}, #{rand(1..1000)}),\n")
end
file.write("(10000, '#{Faker::Name.first_name}', '#{Faker::Name.last_name.gsub("'", "''")}', '#{Faker::IndustrySegments.sub_sector}', #{rand(50_000..150_000)}, #{rand(1..1000)});\n")
file.close
