# frozen_string_literal: true

require 'faker'
require_relative 'lib'

names = get_names
file = File.open('/media/sf_win_lin/contacts_script.sql', 'w')
file.write("INSERT INTO contacts (code, object_code, entity_name, full_name, telephone_number, email) values\n")
9_999.times do |i|
  owner = rand(1..2) == 1 ? "#{rand(1..100_000)}, NULL" : "NULL, '#{names.sample}'"
  file.write("(#{i + 1}, #{owner}, '#{Faker::Name.name_with_middle.gsub("'", "''")}', '#{Faker::PhoneNumber.cell_phone_with_country_code}', '#{Faker::Internet.email}'),\n")
end
owner = rand(1..2) == 1 ? "#{rand(1..100_000)}, NULL" : "NULL, '#{names.sample}'"
file.write("(10000, #{owner}, '#{Faker::Name.name_with_middle.gsub("'", "''")}', '#{Faker::PhoneNumber.cell_phone_with_country_code}', '#{Faker::Internet.email}');\n")
file.close

