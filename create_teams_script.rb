# frozen_string_literal: true

require 'faker'

file = File.open('/media/sf_win_lin/teams_script.sql', 'w')
file.write("INSERT INTO teams (id, leader_id, name, speciality, workers_amount) values\n")
9.times do |i|
  file.write("(#{i + 1}, #{rand(1..10)}, '#{Faker::Company.name}', '#{Faker::IndustrySegments.sector}', #{rand(1..1000)}),\n")
end
file.write("(10, #{rand(1..10)}, '#{Faker::Company.name}', '#{Faker::IndustrySegments.sector}', #{rand(1..1000)});\n")
file.close
