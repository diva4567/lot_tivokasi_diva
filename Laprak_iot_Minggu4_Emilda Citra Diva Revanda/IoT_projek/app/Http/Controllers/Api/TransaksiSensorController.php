<?php

namespace App\Http\Controllers\Api;

use Illuminate\Http\Request;
use App\Models\TransaksiSensor;
use App\Http\Controllers\Controller;
use App\Http\Resources\TransaksiSensorResource;

class TransaksiSensorController extends Controller
{    
    /**
     * Get all TransaksiSensor records (paginated).
     */
    public function index()
    {
        $transaksiSensors = TransaksiSensor::latest()->paginate(5);
        return TransaksiSensorResource::collection($transaksiSensors);
    }

    /**
     * Store a newly created TransaksiSensor.
     */
    public function store(Request $request)
    {
        $validatedData = $request->validate([
            'nama_sensor' => 'required|string|max:255',
            'nilai1' => 'required|integer',
            'nilai2' => 'required|integer',
        ]);

        $transaksiSensor = TransaksiSensor::create($validatedData);

        return response()->json([
            'message' => 'Data successfully created',
            'data' => new TransaksiSensorResource($transaksiSensor)
        ], 201);
    }

    /**
     * Display a specific TransaksiSensor.
     */
    public function show(TransaksiSensor $transaksiSensor)
    {
        return new TransaksiSensorResource($transaksiSensor);
    }

    /**
     * Update a specific TransaksiSensor.
     */
    public function update(Request $request, TransaksiSensor $transaksiSensor)
    {
        $validatedData = $request->validate([
            'nama_sensor' => 'required|string|max:255',
            'nilai1' => 'required|integer',
            'nilai2' => 'required|integer',
        ]);

        $transaksiSensor->update($validatedData);

        return response()->json([
            'message' => 'Data successfully updated',
            'data' => new TransaksiSensorResource($transaksiSensor)
        ], 200);
    }

    /**
     * Delete a specific TransaksiSensor.
     */
    public function destroy(TransaksiSensor $transaksiSensor)
    {
        $transaksiSensor->delete();

        return response()->json([
            'message' => 'Data successfully deleted'
        ], 204);
    }
}
