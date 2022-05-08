# frozen_string_literal: true

require 'faker'
require 'active_support/all'
require_relative 'lib'

objects_file = File.open('/media/sf_win_lin/building_objects_script.sql', 'r')
objects = objects_file.readlines.map { |x| x.split(',') }
objects_file.close

file = File.open('/media/sf_win_lin/work_performance_script.sql', 'w')
file.write("INSERT INTO work_performance (id, object_code, responsible_team, work_object, start_time, finish_time, working_days) values\n")
9.times do |i|
  object = rand(1..100_000)
  term = get_term(object, objects)
  file.write("(#{i + 1}, #{object}, #{rand(1..10)}, '#{Faker::Company.bs}', '#{Faker::Date.between(from: Date.parse(term.first), to: Date.parse(term.second))}', ARRAY [")

  temp_days = []
  7.times { temp_days.push Faker::Date.between(from: Date.today, to: 7.day.from_now).strftime('%A') }
  unique_week = temp_days.uniq
  (unique_week.length - 1).times do |j|
    file.write("'#{unique_week[j]}', ")
  end
  file.write("'#{unique_week.last}']),\n")
end

object = rand(1..100_000)
term = get_term(object, objects)
file.write("(10, #{object}, #{rand(1..10)}, '#{Faker::Company.bs}', '#{Faker::Date.between(from: Date.parse(term.first), to: Date.parse(term.second))}', ARRAY [")

temp_days = []
7.times { temp_days.push Faker::Date.between(from: Date.today, to: 7.day.from_now).strftime('%A') }
unique_week = temp_days.uniq
(unique_week.length - 1).times do |j|
  file.write("'#{unique_week[j]}', ")
end
file.write("'#{unique_week.last}']);\n")

file.close

