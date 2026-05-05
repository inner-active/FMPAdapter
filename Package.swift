// swift-tools-version:5.3

// Created by Digital Turbine on 03/12/2025.
// Copyright © 2025 Digital Turbine. All rights reserved.
// License: https://www.digitalturbine.com/sdk-license-fyber

import PackageDescription

let package = Package(
    name: "FMPAdapter",
    platforms: [.iOS(.v13)],
    products: [
        .library(
            name: "FMPAdapter",
            targets: ["FMPAdapterTarget"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/inner-active/DTExchangeSDK-iOS-SPM", .exact("8.4.7"))
    ],
    targets: [
        .target(
            name: "FMPAdapterTarget",
            dependencies: [
                .target(name: "FMPAdapter"),
                .product(name: "DTExchangeSDK", package: "DTExchangeSDK-iOS-SPM")
            ],
            path: "Sources/FMPAdapterTarget"
        ),
        .binaryTarget(
            name: "FMPAdapter",
            url: "https://cdn2.inner-active.mobi/fmp-sdk/files/FMPAdapter-iOS-SPM-8.4.7.zip",
            checksum: "64ce976129f85f2af0c0cf271e34430ee39e288be68b972ce5afaed5e79f404a" 
        ),
    ]
)