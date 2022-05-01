# frozen_string_literal: true

require 'faker'

file = File.open('/media/sf_win_lin/buildings_script.sql', 'w')
file.write("INSERT INTO buildings (id, object_code, length, width, flats_amount, frame_material) values (\n")
9.times do |i|
  file.write("(#{i + 1}, #{rand(1..100_000)}, #{rand(50..100)}, #{rand(50..100)}, #{rand(50..100)}, '#{Faker::Construction.material}'),\n")
end
file.write("(10, #{rand(1..100_000)}, #{rand(50..100)}, #{rand(50..100)}, #{rand(50..100)}, '#{Faker::Construction.material}')\n)")
file.close
