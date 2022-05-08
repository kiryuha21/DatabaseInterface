# frozen_string_literal: true

require 'faker'

file = File.open('/media/sf_win_lin/entity_script.sql', 'w')
file.write("INSERT INTO entity (name, organization_type, services, legal_address, real_address) values\n")
9.times do
  file.write("('#{Faker::Company.name.gsub("'", "''")}', '#{Faker::Company.industry}', ARRAY [")
  rand(1..3).times { file.write("'#{Faker::Company.bs}', ") }
  file.write("'#{Faker::Company.bs}'], ")
  file.write("'#{Faker::Address.full_address.gsub("'", "''")}', '#{Faker::Address.full_address.gsub("'", "''")}'),\n")
end
file.write("('#{Faker::Company.name.gsub("'", "''")}', '#{Faker::Company.industry}', ARRAY [")
rand(1..3).times { file.write("'#{Faker::Company.bs}', ") }
file.write("'#{Faker::Company.bs}'], ")
file.write("'#{Faker::Address.full_address.gsub("'", "''")}', '#{Faker::Address.full_address.gsub("'", "''")}');\n")
file.close
