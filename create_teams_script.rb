# frozen_string_literal: true

require 'faker'

file = File.open('/media/sf_win_lin/teams_script.sql', 'w')
file.write("INSERT INTO teams (id, leader_id, name, speciality, workers_amount) values\n")
999.times do |i|
  file.write("(#{i + 1}, #{rand(1..10_000)}, '#{Faker::Company.name.gsub("'", "''")}', '#{Faker::IndustrySegments.sector}', #{rand(1..10)}),\n")
end
file.write("(1000, #{rand(1..10_000)}, '#{Faker::Company.name.gsub("'", "''")}', '#{Faker::IndustrySegments.sector}', #{rand(1..10)});\n")
file.close
