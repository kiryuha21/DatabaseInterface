# frozen_string_literal: true

require 'faker'
require_relative 'lib'

names = get_names
file = File.open('/media/sf_win_lin/contacts_script.sql', 'w')
file.write("INSERT INTO contacts (code, object_code, entity_name, full_name, telephone_number, email) values (\n")
9.times do |i|
  file.write("(#{i + 1}, #{rand(1..100_000)}, '#{names.sample}', '#{Faker::Name.name_with_middle}', '#{Faker::PhoneNumber.cell_phone_with_country_code}', '#{Faker::Internet.email}'),\n")
end
file.write("(10, #{rand(1..100_000)}, '#{names.sample}', '#{Faker::Name.name_with_middle}', '#{Faker::PhoneNumber.cell_phone_with_country_code}', '#{Faker::Internet.email}')\n)")
file.close

