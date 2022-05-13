# frozen_string_literal: true

require 'faker'
require 'active_support/all'
require_relative 'lib'

BUILDINGS = ['Residential Building', 'Educational Building', 'Institutional Building', 'Assembly Building',
             'Business Building', 'Mercantile Building', 'Industrial Building', 'Storage Building',
             'Wholesale Establishment', 'Mixed Land Use Building', 'Hazardous Building', 'Detached Building',
             'Semi-Detached Building', 'Multi-Storey or High Rise Building', 'Slum', 'Unsafe Buildings',
             'Special Building', 'Multi-Level Car Parking'].freeze

STATUSES = ['Finished', 'Planning stage', 'Building stage', 'Designing stage', 'Funding stage'].freeze

names = get_names
file = File.open('/media/sf_win_lin/building_objects_script.sql', 'w')
file.write("INSERT INTO building_objects (code, territory_id, developer_name, distributor_name, contractor_name, designer_name, title, address, start_of_construction, deadline, status) values\n")
99_999.times do |i|
  file.write("(#{i + 1}, #{rand(1..100)}, '#{names.sample}', '#{names.sample}', '#{names.sample}', '#{names.sample}', '#{BUILDINGS.sample}', '#{Faker::Address.street_address.gsub("'", "''")}', '#{Faker::Date.between(from: 1.year.from_now, to: 2.years.from_now)}', '#{Faker::Date.between(from: 3.year.from_now, to: 5.year.from_now)}', '#{STATUSES.sample}'),\n")
end
file.write("(100000, #{rand(1..100)}, '#{names.sample}', '#{names.sample}', '#{names.sample}', '#{names.sample}', '#{BUILDINGS.sample}', '#{Faker::Address.street_address.gsub("'", "''")}', '#{Faker::Date.between(from: 1.year.from_now, to: 2.year.from_now)}', '#{Faker::Date.between(from: 3.year.from_now, to: 5.year.from_now)}', '#{STATUSES.sample}');\n")
file.close
