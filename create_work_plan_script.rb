# frozen_string_literal: true

require 'faker'

BOOLS = %w[TRUE FALSE].freeze

file = File.open('/media/sf_win_lin/work_plan_script.sql', 'w')
file.write("INSERT INTO work_plan (id, object_code, target, budget, term, done) values\n")
9.times do |i|
  file.write("(#{i + 1}, #{rand(1..100_000)}, '#{Faker::Company.bs}', #{rand(1_000_000..100_000_000)}, 'no of days #{rand(50..400)}:00:00', #{BOOLS.sample}),\n")
end
file.write("(10, #{rand(1..100_000)}, '#{Faker::Company.bs}', #{rand(1_000_000..100_000_000)}, 'no of days #{rand(50..400)}:00:00', #{BOOLS.sample});\n")
file.close
